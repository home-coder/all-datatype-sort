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

static void sort_char(char **single, char **sort_single)
{
	int i = 0, j;
	int len = strlen(*single);
	char tmp;
	*sort_single = (char *)malloc(sizeof(char) * (len + 1));	
	printf("%d\n", len);
	for (; i < len - 1; i++) {
		for (j = i + 1; j < len-i-1; j++) {
			if (*single[i] > *single[j]) {
				*sort_single[i] = *single[j];
			} else {
				*sort_single[i] = *single[i];
			}
		}
	}
	*sort_single[len] = '\0';
	printf("%s \n", *sort_single);
}

int main()
{
	int a[] = {1, 3, 5, 2, 6, 8, 4}, i;
	int len = sizeof(a)/sizeof(a[0]);
	sort_intarr(a, len);
	for (i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

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

	char *single = "jfdlsjflkdsa";
	char *sort_single;
	sort_char(&single, &sort_single);
	printf("%s\n", sort_single);

	return 0;
}
