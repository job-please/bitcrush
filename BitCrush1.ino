// defining hardware resources
//https://www.electrosmash.com/pedalshield-uno

// defining PWM parameters
#define PWM_FREQ 0x00FF // pwm frequency 31.3KHz
#define PWM_MODE 0
#define PWM_QTY 2 //2 pwms in parallel

// other vars
unsigned int input = 0;
unsigned int output = 0;
unsigned int ADC_low, ADC_high;

unsigned int bitDif = 15;

void setup()
{
  Serial.begin(115200);

  // set up ADC
  ADMUX = 0x60; // left adjust, adc0, internal vcc
  ADCSRA = 0xe5; // turn on adc, ck/32 auto trigger
  ADCSRB = 0x07; // t1 capture for trigger
  DIDR0 = 0x01; // turn off digital inputs for adc0

  // set up PWM
  TCCR1A = (((PWM_QTY - 1) << 5) | 0x80 | (PWM_MODE << 1)); //
  TCCR1B = ((PWM_MODE << 3) | 0x11); // ck/1
  TIMSK1 = 0x20; // interrupt on capture interrupt
  ICR1H = (PWM_FREQ >> 8);
  ICR1L = (PWM_FREQ & 0xff);
  DDRB |= ((PWM_QTY << 1) | 0x02); // turn on outputs

  // turn on interrupts - not really necessary with arduino
  sei();
}

void loop()
{
  
}


// timer 1 interruption
ISR(TIMER1_CAPT_vect)
{
  ADC_low = ADCL; // low byte to be fetched first
  ADC_high = ADCH;

  // construct the sample
  input = ((ADC_high << 8) | ADC_low) + 0x8000;
  output = (input >> bitDif) << bitDif;

  // Write PWM signal
  OCR1BL = output >> 8;
  OCR1AL = output & 0xFF; // low byte
}

