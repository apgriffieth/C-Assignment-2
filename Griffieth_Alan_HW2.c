#include <stdio.h>
#include <stdlib.h>

void diceRoll(int, int);
void characterGenerator(int);
void macrosVsFunctions();

int subf(int, int);
int cubef(int);
int minf(int, int);
int oddf(int);

#define subm(x, y) (x-y)
#define cubem(x) (x*x*x)
#define minm(x, y) ((x < y) ? x : y)
#define oddm(x) ((x % 2 == 0) ? 0 : 1)

int main(int argc, char** argv)
{
  int choice, diceSides, diceNumber, seed;
  do{
    printf("Welcome to the fantasy player fun tool!\n");
    printf("Menu:\n");
    printf("1 - Dice Roll Showdown\n");
    printf("2 - Generate a Character\n");
    printf("3 - Macros vs Functions Throw-down\n");
    printf("0 - Quit\n");
    printf("Choose an option:\n");

    scanf("%d", &choice);
  
    switch(choice){
    case 1:
      printf("\n\nWelcome to the Dice Roll Showdown!\n");
      printf("How many sides do the dice have (input a positive number): ");
      scanf("%d", &diceSides);

      printf("How many dice will each player roll? ");
      scanf("%d", &diceNumber);
      
      diceRoll(diceSides, diceNumber);
      break;
    case 2:
      seed = 10000 + rand() / (RAND_MAX / (99999 - 10000 + 1) + 1);
      //creates a random number between 10000 and 99999

      characterGenerator(seed);
      break;

    case 3:
      macrosVsFunctions();
      break;

    case 0:
      printf("Goodbye!\n");
      break;

    default : 
      printf("Error. Please try again!\n\n");
      break;
    }
  }
  while(choice != 0);
    
  return 0;
}

void diceRoll(int sides, int dice)
{
  int total1, total2 = 0;
  int roll, i;
  printf("\nPlayer 1 Rolled:\n");
  for(i = 0; i < dice; i++)
    {
      roll = 1 + rand() / (RAND_MAX / (sides - 1 + 1) + 1); 
      //this modifies the rand() range so that it is within 1 to sides.
      total1 += roll;
      printf("%d\n", roll);
    }
  printf("Total: %d\n\n", total1);

  printf("Player 2 Rolled:\n");
  for(i = 0; i < dice; i++)
    {
      roll = 1 + rand() / (RAND_MAX / (sides - 1 + 1) + 1);
      total2 += roll;
      printf("%d\n", roll);
    }
  printf("Total: %d\n\n", total2);

  if(total2 > total1)
    {
      printf("Player 2 Wins!\n\n");
    }

  else if(total1 > total2)
    {
      printf("Player 1 Wins!\n\n");
    }

  else
    {
      printf("Tie Game, Nobody Wins!\n\n");
    }
}

void characterGenerator(int seed)
{
  printf("\n\nWelcome to the Fantasy Character Generator!\n");
  printf("Seed Generated %d:\n", seed);

  int digit1, digit2, digit3, digit23, digit4, digit5;
  digit1 = seed / 10000;
  digit2 = (seed % 10000) / 1000;
  digit3 = (seed % 1000) / 100;
  digit4 = (seed % 100) / 10;
  digit5 = (seed % 10);
  digit23 = (10 * digit2) + digit3;

  if(digit1 % 2 == 0)//The first digit is even
    {
      printf("%d - Good\n", digit1);
    }
  else
    {
      printf("%d - Evil\n", digit1);
    }

  FILE *infile;
  char buffer[30];
  infile = fopen("hwNames.txt", "r");
  if(infile == NULL)
    {
      printf("Not getting file\n");
    }  
  int i, end = 0;
  for(i = 0; i < digit23; i++)
    {
      if(0==fgets(buffer, sizeof(buffer), infile))
	{
	  end = 1; //we are at the name at digit23
	}
    }
  if(!end)
    {
      printf("%d%d - %s", digit2, digit3, buffer);
    }
  fclose(infile);

  switch(digit4)
    {
    case 0:
      printf("%d - Human\n", digit4);
      break;
    
    case 1:
      printf("%d - Elf\n", digit4);
      break;

    case 2:
      printf("%d - Halfling\n", digit4);
      break;
      
    case 3:
      printf("%d - Gnome\n", digit4);
      break;

    case 4:
      printf("%d - Dwarf\n", digit4);
      break;

    case 5:
      printf("%d - Half-Elf\n", digit4);
      break;

    case 6:
      printf("%d - Kobold\n", digit4);
      break;

    case 7:
      printf("%d - Half-Ord\n", digit4);
      break;

    case 8:
      printf("%d - Dragon-kin\n", digit4);
      break;

    case 9:
      printf("%d - Construct\n", digit4);
      break;
    }

  switch(digit5)
    {
    case 0:
      printf("%d - Barbarian\n", digit5);
      break;

    case 1:
      printf("%d - Bard\n", digit5);
      break;

    case 2:
      printf("%d - Cleric\n", digit5);
      break;

    case 3:
      printf("%d - Druid\n", digit5);
      break;

    case 4:
      printf("%d - Fighter\n", digit5);
      break;

    case 5:
      printf("%d - Wizard\n", digit5);
      break;

    case 6:
      printf("%d - Monk\n", digit5);
      break;

    case 7:
      printf("%d - Paladin\n", digit5);
      break;

    case 8:
      printf("%d - Ranger\n", digit5);
      break;

    case 9:
      printf("%d - Rogue\n", digit5);
      break;
    }
  int input, newSeed;
  do
    {
      printf("\nWould you like to generate another character? (1 - yes, 0 - no): ");
      scanf("%d", &input);
      switch(input)
	{
	case 1:
	  newSeed = 10000 + rand() / (RAND_MAX / (99999 - 10000 + 1) + 1);
	  characterGenerator(newSeed);
	  break;
	  
	case 0:
	  printf("\n\n");
	  break;

	default:
	  printf("Incorrect input, please enter a 0 or 1!\n");
	  break;
	}
    }
  while(input != 0 && input != 1);
}

int subf(int a, int b)
{
  return a - b;
}

int cubef(int a)
{
  return a * a * a;
}

int minf(int a, int b)
{
  if (a <= b)
    {
      return a;
    }
  else
    {
      return b;
    }
}

int oddf(int a) 
{
  if (a % 2 == 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

void macrosVsFunctions()
{
  /*Answers for this area may differ from function to macro because of the way 
    that macros work. Because the code for a macro is shoved right in, any 
    values that are pre or post incremented/decremented may give unwanted 
    effects as they will change every time the value is plugged into the macro.
  */

  int num1 = 5, num2 = 7;
  int fAnswer, mAnswer;
  printf("\n\nnum1: %d, num2: %d\n\n", 5, 7);
  fAnswer = subf(num1, num2);
  num1 = 5;
  num2 = 7;
  mAnswer = subm(num1, num2);
  printf("Subtraction Normal\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);

  num1 = 5;
  num2 = 7;
  fAnswer = subf(num1++, num2--);
  num1 = 5;
  num2 = 7;
  mAnswer = subm(num1++, num2--);
  printf("Subtraction num1 Post-Incremented, num2 Post-Decremented\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);

  num1 = 5;
  num2 = 7;
  fAnswer = cubef(num1);
  num1 = 5;
  num2 = 7;
  mAnswer = cubem(num1);
  printf("Cubing num1 Normal\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);

  num1 = 5;
  num2 = 7;
  fAnswer = cubef(--num1);
  num1 = 5;
  num2 = 7;
  mAnswer = cubem(--num1);
  printf("Cubing num1 Pre-Decremented\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);

  num1 = 5;
  num2 = 7;
  fAnswer = minf(num1, num2);
  num1 = 5;
  num2 = 7;
  mAnswer = minm(num1, num2);
  printf("Finding Minimum Normal\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);

  num1 = 5;
  num2 = 7;
  fAnswer = minf(--num1, --num2);
  num1 = 5;
  num2 = 7;
  mAnswer = minm(--num1, --num2);
  printf("Finding Minimum with both Values Pre-Decremented\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);

  num1 = 5;
  num2 = 7;
  fAnswer = oddf(num1);
  num1 = 5;
  num2 = 7;
  mAnswer = oddm(num1);
  printf("Seeing if num1 is Odd Normal\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);

  num1 = 5;
  num2 = 7;
  fAnswer = oddf(num1++);
  num1 = 5;
  num2 = 7;
  mAnswer = oddm(num1++);
  printf("Seeing if num1 is Odd Post-Incremented\nFunction Value: %d\nMacro Value: %d\n\n", fAnswer, mAnswer);
}
