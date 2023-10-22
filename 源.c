#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>;
#include<stdbool.h>;
#define Maxsize 100
typedef struct Sqlist {
	int data[Maxsize];
	int length;
}Sqlist;
//初始化顺序表
void InitList(Sqlist*L) {
	L->length = 0;
	memset(L->data, 0, sizeof(L->data));

}
//销毁顺序表
void DestoryList(Sqlist* L) {
	free(L);
}
//顺序表长
int Length(Sqlist L) {
	return L.length;
}
//判断是否为空
bool isEmpty(Sqlist L) {
	return (L.length == 0);
}
//输出线性表
void Print(Sqlist L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}
//查找元素值
int LocateElem(Sqlist L, int x) {
	int i = 0;
	while (i < L.length && L.data[i] != x) {
		i++;
	}
	if (i >= L.length) {
		return 0;
	}
	else {
		return i + 1;
	}
}
//返回L中p位置的元素值 
int getElem(Sqlist L, int p) {
	if (p<0 || p>L.length - 1)
		return ;
	return L.data[p];
}
//在位置p插入元素
void Insert(Sqlist* L, int p, int e) {
	if (p<0 || p>L->length||L->length >= Maxsize) {
		return;
	}
	for (int i = L->length - 1; i >= p; --i) {
		L->data[i + 1] = L->data[i];
	}
	L->data[p] = e;
	++L->length;
}
//删除p位置的元素 
void Delete(Sqlist* L, int p) {
	if (p<0 || p>L->length - 1) {
		return;
	}
	for (int i = p; i < L->length; i++) {
		L->data[i] = L->data[i + 1];
	}
	--(L->length);
}
int main() {
	Sqlist L;
	InitList(&L);
	Insert(&L, 0, 1);
	Insert(&L, 1, 2);
	Insert(&L, 2, 3);
	Delete(&L, 0);
	int k = getElem(L, 2);
	printf("%d-\n", k);
	int x = LocateElem(L, 3);
	printf("%d--\n", x);
	printf("表长%d\n", Length(L));
	Print(L);
	printf("%d",isEmpty(L));
}