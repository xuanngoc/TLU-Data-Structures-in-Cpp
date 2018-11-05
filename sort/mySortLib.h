
/////
void bubbleSort(int arr[], int n){
	for(int i=0; i< n-1; i++){
		for(int j=0; j< n -i -1; j++){
			if(arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
}
void selectionSort(int arr[], int n){
	for(int i=0; i< n-1 ; i++)
		for (int j = i+1; j < n; j++)
			if (arr[i] > arr[j]){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}

//merge Sort
void merge(int arr[], int left, int mid, int right){
	int x = left;
	int y = mid + 1;
	int *tmp = new int[right - left + 1];
	
	for(int i=0; i<= right - left; i++){
		if( arr[x] < arr[y]){
			tmp[i] = arr[x];
			x++;
		}else{
			tmp[i] = arr[y];
			y++;
		}
		if( x == mid +1){
			while(y <= right){
				i++;
				tmp[i] = arr[y];
				y++;
			}
			break;
		}
		if( y == right +1){
			while(x <= mid){
				i++;
				tmp[i] = arr[x];
				x++;
			}
			break;
		}
	}
	for (int k = 0; k <= right - left; k++) 
		arr[left + k] = tmp[k];
	delete tmp;
	print(arr, right);

}

void mergeSort(int arr[], int left, int right){
	if( left < right ){
		int mid = (left + right ) / 2;
		//cout<<"-------"<<mid<<endl;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);

		merge(arr, left, mid, right);
	}
}