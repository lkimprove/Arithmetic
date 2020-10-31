void BubbleSort(int* array, int n){
    for(int i = n; i > 1; i--){
        int end = 0;
        
        for(int j = 1; j < i; j++){
            if(array[j - 1] > array[j]){
                swap(array[j - 1], array[j]);
                end = 1;
            }
        }
        
        if(end == 0){
            break;
        }
    }
}
