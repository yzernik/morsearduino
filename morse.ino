/*
  Morse
  Should do Morse Code.
 */
 

#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

static const struct
{
   const char letter, *morse;
} Code[] =
{
   { 'A', ".- "   },{ 'B', "-... " },{ 'C', "-.-. " },{ 'D', "-.. "  },
   { 'E', ". "    },{ 'F', "..-. " },{ 'G', "--. "  },{ 'H', ".... " },
   { 'I', ".. "   },{ 'J', ".--- " },{ 'K', ".-.- " },{ 'L', ".-.. " },
   { 'M', "-- "   },{ 'N', "-. "   },{ 'O', "--- "  },{ 'P', ".--. " },
   { 'Q', "--.- " },{ 'R', ".-. "  },{ 'S', "... "  },{ 'T', "- "    },
   { 'U', "..- "  },{ 'V', "...- " },{ 'W', ".-- "  },{ 'X', "-..- " },
   { 'Y', "-.-- " },{ 'Z', "--.. " },{ ' ', "       "    },
};

int led = 13;
int morse_unit = 100;

void dot() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1*morse_unit);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1*morse_unit);               // wait for a second
}

void dash() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(3*morse_unit);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1*morse_unit);               // wait for a second
}

void space() {
  delay(1*morse_unit);
}

void encode_letter(const char *c)
{
   size_t i;
   i = 0;
   while(c[i] != '\0')
     {
       Serial.println(c[i]); 
        if(c[i] == '.')
          {
            dot();
          }  
        if(c[i] == '-')
          {
            dash();
          } 
        if(c[i] == ' ')
          {
            space();
          } 
        i++;
     }
}

void encode_string(const char *s)
{
   size_t i, j;
   for ( i = 0; s[i]; ++i )
   {
      for ( j = 0; j < sizeof Code / sizeof *Code; ++j )
      {
         if ( toupper(s[i]) == Code[j].letter )
         {
            Serial.println(Code[j].letter); 
            Serial.println(Code[j].morse); 
            encode_letter(Code[j].morse);
            break;
         }
      }
   }
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  const char text[] = "Hello, Arduino";
  encode_string(text);
  delay(2000);
}


