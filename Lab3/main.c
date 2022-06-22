#include <stdio.h>
#include "image.h"


int main() {
	uint16_t histogram;           
	uint16_t *p_hist;         
	p_hist = &histogram;
	uint16_t *p_hist_result;
	FILE *file;
	p_hist_result = EightBitHistogram(WIDTH1, HEIGTH1, p_start_image1, &histogram);

	file = fopen("Histogram.csv", "w+");
	fprintf(file,"X, Y\n", NULL);
	if((file=fopen ("Histogram.csv","w+")) != NULL)
	{
		for(int i =0; i < 256; i = i + 1)
		{
			fprintf(file,"%d; '%d'\n",i,p_hist_result[i]);
			p_hist[i]=0;
		}
		fclose(file);
	}

	while (1)
	{
		/* holds the program here */
	}
	
	return 0; //  just to avoid, should not reach here
}

