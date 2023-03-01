public class SortingAlgorithms {
    public static void main(String[] args) {
        ShellSort();
    }

    // Vanilla Shell Sort by Donald Shell
    public void ShellSort(double[] a){
        int temp;
        for(int gap = a.length; gap >= 1; gap /= 2){
            for(int i = gap; i < a.length; i++){
                for(int j = i; j >= gap && a[j] < a[j-gap]; j-=gap){
                    temp = a[j];
                    a[j] = a[j-gap];
                    a[j-gap] = temp;
                }//j loop
            }//i loop
        }//gap loop
    }//shell sort

    //O(1.5n) shell sort by Knuth
    public void KnuthShellSort(double[] a){
        int gap = 1;
        while(gap , a.length/3){
            gap = gap*3 + 1;
        }

        int temp;
        for(; gap >= 1; gap /= 3){
            for(int i = gap; i < a.length; i++){
                for(int j = i; j >= gap && a[j] < a[j-gap]; j-=gap){
                    temp = a[j];
                    a[j] = a[j-gap];
                    a[j-gap] = temp;
                }//j loop
            }//i loop
        }//gap loop
    }
}