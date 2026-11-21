#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#define COMM "termux-wallpaper -f "
#define PATH "/storage/emulated/0/wall/"
#define BUFFER_SIZE 256
#define SLEEP_TIME 600


const char* const images[] = 
{
"0.png",
"1.png",
"2.png",
"3.jpg",
"4.jpg",
"5.jpg",
"6.png",
"7.png",
"8.png",
"9.jpg",
"10.jpg",
"11.jpg"
};

char buffer[BUFFER_SIZE];

void SetWall(uint8_t l)
{
	uint8_t r = rand() % (sizeof(images) / sizeof(images[0]));
	uint8_t b = 0;
	uint8_t c = 0;

	while(COMM[c] != '\0')
	{
		buffer[b] = COMM[c];
		b++;
		c++;
	}

	c = 0;

	while(PATH[c] != '\0')
	{
		buffer[b] = PATH[c];
		b++;
		c++;
	}

	c = 0;
	
	while(images[r][c] != '\0')
	{
		buffer[b] = images[r][c];
		b++;
		c++;
	}

	if (l == 1)
	{
		buffer[b] = ' ';
		b++;
		buffer[b] = '-';
		b++;
		buffer[b] = 'l';
		b++;
	}

	buffer[b] = '\0';
}


int main ()
{

	srand(time(NULL));

	while(1)
	{
		sleep(SLEEP_TIME);
		
		SetWall(0);
		system(buffer);
		
		SetWall(1);
		system(buffer);
	}

	return 0;
}
