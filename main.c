#include <stdio.h>
#include <math.h>

struct data {
	long long d1;
	long long d2;
	long long d3;
	long long d4;
	int d5;
};
void Data(struct data stu[105]);

struct rule {
	long long r1;
	long long r2;
	long long r1a;
	long long r1b;
	long long r2a;
	long long r2b;
	long long r11;
	long long r12;
	long long r13;
	long long r14;
	long long r15;
	long long r21;
	long long r22;
	long long r23;
	long long r24;
	long long r25;
	long long r31;
	long long r32;
	long long r41;
	long long r42;
	char r5[20];
};
void Rule(struct rule stu1[1000]);

int main() {
	FILE *fp;
	int i, j;
	int a;
	struct data stu[105];
	fp = fopen("C:\\Users\\离忧\\hanjiazuoye2\\数据1.txt", "r");
	for (i = 0; i < 100; i++) {
		fscanf(fp, "%lld %lld %lld %lld %d", &stu[i].d1, &stu[i].d2, &stu[i].d3, &stu[i].d4, &stu[i].d5);
	}
	fclose(fp);
	struct rule stu1[1000];
	fp = fopen("C:\\Users\\离忧\\hanjiazuoye2\\规则1.txt", "r");
	for (i = 0; i < 1000; i++) {
		fscanf(fp, "%lld.%lld.%lld.%lld/%lld %lld.%lld.%lld.%lld/%lld %lld : %lld %lld : %lld %s", &stu1[i].r11, &stu1[i].r12,
		       &stu1[i].r13, &stu1[i].r14,
		       &stu1[i].r15, &stu1[i].r21, &stu1[i].r22, &stu1[i].r23, &stu1[i].r24, &stu1[i].r25, &stu1[i].r31, &stu1[i].r32,
		       &stu1[i].r41,
		       &stu1[i].r42, stu1[i].r5);
		stu1[i].r1 = stu1[i].r11 * 256 * 256 * 256 + stu1[i].r12 * 256 * 256 + stu1[i].r13 * 256 + stu1[i].r14;
		stu1[i].r1a = stu1[i].r1; //- (stu1[i].r1 % int(pow(10, double(32 - stu1[i].r15))));
		stu1[i].r1b = stu1[i].r1a; //+ (pow(10, double(32 - stu1[i].r15)));
		stu1[i].r2 = stu1[i].r21 * 256 * 256 * 256 + stu1[i].r22 * 256 * 256 + stu1[i].r23 * 256 + stu1[i].r24;
		stu1[i].r2a = stu1[i].r2 ;//- (stu1[i].r2 % int(pow(10, double(32 - stu1[i].r15))));
		stu1[i].r2b = stu1[i].r2a; //+ (pow(10, double(32 - stu1[i].r15)));
	}
	fclose(fp);//读取文件数据并赋值到结构体中
	rewind(fp);
	fp = fopen("C:\\Users\\离忧\\hanjiazuoye2\\res.txt", "r+");
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 950; j++) {
			if (stu[i].d3 >= stu1[j].r31 && stu[i].d3 <= stu1[j].r32 && stu[i].d4 >= stu1[j].r41 && stu[i].d4 <= stu1[j].r42) {
				if (stu[i].d1 >= stu1[j].r1a && stu[i].d1 <= stu1[j].r1b && stu[i].d2 >= stu1[j].r2a
				        && stu[i].d2 <= stu1[j].r2b) {
					printf("%d\n", j);
					fprintf(fp, "%d\n", j);
					break;
				}
			}
		}
	}
	fclose(fp);//数据匹配并将答案存入文件
	return 0;
}