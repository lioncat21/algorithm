//Ѱ�������е�N�����
int findNo_N(int *pnum, int length, int N)
{
	//����ð�������һ��ѭ�����ҳ������еļ���ֵ
	for (int i = 0; i < length - 1; i++) {
		if (pnum[i] > pnum[i + 1]) {
			int temp = pnum[i];
			pnum[i] = pnum[i + 1];
			pnum[i + 1] = temp;
		}
	}
	//���N���ڴ���1����ݹ�Ѱ��ȥ�����ֵ��������еļ���ֵ��֪��N����1��
	//���ǰ�����εݹ��ҵ�����������ȣ���N��ֵ���䣬�����ݹ顣
	//����Ҳ���������-1
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