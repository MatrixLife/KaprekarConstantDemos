// Number495.cpp : 定义控制台应用程序的入口点。
//
#include <conio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CONST_495 495

int _generate_random_value()
{
	return 100 + (int)(rand() / (float)(RAND_MAX) * 899.0f);
};
void _sort_chars_ascend(char* ptr)
{
/**/
	size_t size = strlen(ptr);
	size_t i, j;
	char   tmp_val;
/**/
	if(size > 1)
	{
		for(i = size - 1; i > 0; i--)
		{
			for(j = 0; j < i; j++)
			{
				if(ptr[j] > ptr[j + 1])
				{
					tmp_val = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = tmp_val;
				}
			}
		}
	}
};
void _sort_chars_descend(char* ptr)
{
/**/
	size_t size = strlen(ptr);
	size_t i, j;
	char   tmp_val;
/**/
	if(size > 1)
	{
		for(i = size - 1; i > 0; i--)
		{
			for(j = 0; j < i; j++)
			{
				if(ptr[j] < ptr[j + 1])
				{
					tmp_val = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = tmp_val;
				}
			}
		}
	}
};
void main(int argc, const char* argv[])
{
/**/
	int arg_value = 0;
	int raw_value = 0;
	int asc_value;
	int dsc_value;
	char digit_chars[8] = { NULL };
	size_t rounds = 0;
/**/
	cprintf("Kaprekar Constant demo (3-digit_chars)\r\n");
	srand(time(NULL));
	if(argc > 1)
	{
		arg_value = atoi(argv[1]);
		if(arg_value >= 100 && arg_value <= 999)
		{
			raw_value = arg_value;
			cprintf("Got valid number from argument: %d.\r\n", raw_value);
		}
		else
		{
			raw_value = _generate_random_value();
			cprintf("Got invalid number from argument: %d, use auto-generated random value: %d.\r\n", arg_value, raw_value);
		}
	}
	else
	{
		raw_value = _generate_random_value();
		cprintf("No number supplied from argument, use auto-generated random value: %d.\r\n", raw_value);
	}
	cprintf("\r\n");
	while(1)
	{
		rounds+= 1;
		cprintf("Round %d (number = %d)\r\n", rounds, raw_value);
		sprintf(digit_chars, "%d", raw_value);

		_sort_chars_descend(digit_chars);
		dsc_value = atoi(digit_chars);
		cprintf("    Descending sorted value: %d.\r\n", dsc_value);

		_sort_chars_ascend(digit_chars);
		asc_value = atoi(digit_chars);
		cprintf("    Ascending sorted value: %d.\r\n", asc_value);

		raw_value = dsc_value - asc_value;
		if(raw_value != CONST_495)
		{
			cprintf("    Generating new number by subtract: %d - %d = %d (continue...).\r\n", dsc_value, asc_value, raw_value);
			continue;
		}
		else
		{
			cprintf("    Generating new number by subtract: %d - %d = %d (that's it!)\r\n", dsc_value, asc_value, raw_value);
			break;
		}
	}

	cprintf("\r\n");
	cprintf("Finished within %d rounds. Press any key to exit.\r\n", rounds);
	getch();
};