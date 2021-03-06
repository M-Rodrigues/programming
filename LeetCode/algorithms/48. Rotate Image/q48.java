class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i; j < matrix[i].length; j++) {
                int aux = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = aux;
            }
            
            for (int j = 0; j < matrix[i].length/2; j++) {
                int aux = matrix[i][matrix[i].length - j - 1];
                matrix[i][matrix[i].length - j - 1] = matrix[i][j];
                matrix[i][j] = aux;
            }
        }
    }
}