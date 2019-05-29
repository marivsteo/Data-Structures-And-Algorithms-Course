#include "Set.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stdio.h>

int main() {
	testAll();
	printf("ok");
	testAllExtended();
	printf("ok");

	return 0;
}