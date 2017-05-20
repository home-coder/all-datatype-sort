#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void sort_intarr(int *arr, int len)
{
	int i = 0, j, tmp;
	
	for (; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

static void sort_ch(char *pno, int len)
{
	int i = 0, j;
	char tmp;

	for (; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			if (pno[i] > pno[j]) {
				tmp = pno[i];
				pno[i] = pno[j];
				pno[j] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		printf("%c ", pno[i]);
	}
	printf("\n");
}

static void sort_str(char **strarr, int len)
{
	int i = 0, j;
	char *strtmp;

	for (; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
		if (strlen(strarr[i]) > strlen(strarr[j])) {
			strtmp = strarr[i];
			strarr[i] = strarr[j];
			strarr[j] = strtmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		printf("%s ", strarr[i]);
	}
	printf("\n");
}

static void sort_char(char *single, char *sort_single)
{
	int i = 0, j;
	int len = strlen(single);
	printf("---%d\n", len);
	char tmp;
	for (; i < len - 1; i++) {
		for (j = i + 1; j < len + 1; j++) {
			if (single[i] > single[j]) {
				sort_single[i] = single[j];
			} else {
				sort_single[i] = single[i];
			}
		}
	}
	sort_single[len + 1] = '\0';
	printf("sort single:%s \n", sort_single);
}

static void sort_str2(char **s)
{
	for (; *s != NULL; s++) {
		printf("%s ", *s);
	}
	printf("\n");
}

static void sort_char2(char *src, char **dst)
{
	int i, j;
	int len = strlen(src);
	char tmp;
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	memset(*dst, 0x0, len);
	memcpy(*dst, src, len);

	for (i = 0; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			if ((*dst)[i] > (*dst)[j]) {
				tmp = (*dst)[i];
				(*dst)[i] = (*dst)[j];
				(*dst)[j] = tmp;
			}
		}
	}

	printf("sort_char2 %s\n", *dst);
}

int main()
{
//整型数组
	int a[] = {1, 3, 5, 2, 6, 8, 4}, i;
	int len = sizeof(a)/sizeof(a[0]);
	sort_intarr(a, len);
	for (i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
//字符型数组 1	
	char no[] = {'a', 'd', 'b', 't'};
	int nolen = sizeof(no)/sizeof(no[0]);
	sort_ch(no, nolen);
	for (i = 0; i < nolen; i++) {
		printf("%c ", no[i]);
	}
	printf("\n");
//2.1 字符数组  2, 指向字符串常量....这里面single指向字符串常量的首地址, 字符串常量本身在别处,在常量区
	char *single = "jfdlsjflkdsa";
	char *sort_single = malloc(sizeof(char) * (strlen(single) + 1));

	sort_char(single, sort_single);

//2.2 满足项目README中的需求，将内存申请放到调用的函数内部
	{
		char *src = "fjdlswiae";
		char *dst;
		sort_char2(src, &dst);
		printf("func over: %s\n", dst);
	}

//3.1 模拟字符串 数组, ....这里面的字符串仅仅是将自己的地址存到这个指针数组里，他们本身在别处。s 指向"hellowfdsa"的地址
	char *s[] = {
		"hellowjfld",
		"jfdlksjaf",
		"fjdjoiea"
	};
	char **ps = s;
	len = sizeof(s)/sizeof(s[0]);
	sort_str(ps, len);
	for (i = 0; i < len; i++) {
		printf("%s ", ps[i]);
	}
	printf("\n");

// 3.2  针对3.1排序必须有len，但是遍历就可以通过NULL来优化
	{
		char *s[] = {
			"hellowjlfd",
			"fjldsa",
			"oewafjldsl",
			NULL
		};

		char **ps = s;
		sort_str2(ps);
		for (i = 0; i < len; i++) {
			printf("%s ", ps[i]);
		}
	printf("\n");
	}
//4.0 特定的初始化-->README.md
	{
		int a[10] = {[1 ... 3] = 0, [4 ... 9] = 2};
	}
//4.1 特定的初始化
	{
		int a[][3];
		a[0] = {1, 2, 3};
	}

	return 0;
}
