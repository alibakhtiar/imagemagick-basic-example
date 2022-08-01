// gcc imagemagick.c -lm `pkg-config --cflags --libs MagickWand` -o magick

#include <stdio.h>
#include <assert.h>
#include <MagickWand/MagickWand.h>

void ThrowWandException(MagickWand* wand)
{
	char* description;
	ExceptionType severity;

	description = MagickGetException(wand,&severity);
	(void) fprintf(stderr,"%s %s %lu %s\n",GetMagickModule(),description);
	description=(char *) MagickRelinquishMemory(description);
}

int main(int argc, char **argv)
{
	MagickWand* m_wand = NULL;
	MagickBooleanType status;
	int width, height;

	if (argc < 2) {
		printf("usage: ./magick image\n");
		return 0;
	}

	MagickWandGenesis();

	m_wand = NewMagickWand();
	assert(m_wand != NULL);

	status = MagickReadImage(m_wand, argv[1]);

	if (status == MagickFalse) {
		ThrowWandException(m_wand);
		return 1;
	}

	// Get the image's width and height
	width = MagickGetImageWidth(m_wand);
	height = MagickGetImageHeight(m_wand);

	printf("Image size %dx%d\n", width, height);

	// Clean up
	if(m_wand) {
		m_wand = DestroyMagickWand(m_wand);
		m_wand = NULL;
	}

	MagickWandTerminus();

	return 0;
}
