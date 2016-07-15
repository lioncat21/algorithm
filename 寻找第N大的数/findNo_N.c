//寻找数组中第N大的数
int findNo_N(int *pnum, int length, int N)
{
	//利用冒泡排序的一次循环，找出数组中的极大值
	for (int i = 0; i < length - 1; i++) {
		if (pnum[i] > pnum[i + 1]) {
			int temp = pnum[i];
			pnum[i] = pnum[i + 1];
			pnum[i + 1] = temp;
		}
	}
	//如果N等于大于1，则递归寻找去除最大值后的数组中的极大值，知道N等于1，
	//如果前后两次递归找到的两个数相等，则N的值不变，继续递归。
	//如果找不到，返回-1
	if (N == 1 && (pnum[length - 1] != pnum[length])) {
		return pnum[length - 1];
	}else if (N > 1 && (pnum[length - 1] != pnum[length])) {
		return findNo_N(pnum, length - 1, N - 1);
	}else if (pnum[length - 1] == pnum[length]) {
		return findNo_N(pnum, length - 1, N);
	}else{
		return -1;
	}
}