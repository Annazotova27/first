#pragma ones
struct ArrayInfo {
int* ar;
int size;
int ind_max;
int ind_min;
double mean;
};
void getInfoArray(struct ArrayInfo* arInfo);
struct MinMax {
int ind_min;
int ind_max;
};
struct MinMax GetMaxMin(const int* ar, int size);
struct CountNum {
int pos;
int neg;
int zero;
}
;
struct CountNum GetStatNumber(const int* ar, int size);
int* CreateAr(int size, int min, int max);
