#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

struct data {
	char i1[20];
	char i2[20];
	char i3[20];
	char i4[20];
	char i5[20];
};
void Data(struct data stu[105]);

int main() {
	FILE *fp;
	int i;
	struct data stu[105];
	fp = fopen("C:\\Users\\ÀëÓÇ\\Êı¾İ1.txt", "r");
	for (i = 0; i < 100; i++) {
		fscanf(fp, "%s %s %s %s %s", stu[i].i1, &stu[i].i2, &stu[i].i3, &stu[i].i4, &stu[i].i5);
		printf("%s %s %s %s %s\n", stu[i].i1, stu[i].i2, stu[i].i3, stu[i].i4, stu[i].i5);
	}
	fclose(fp);
	return 0;
}