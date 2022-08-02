void segment_mmult(int initPos,int offset,int ncols, double *aa, double *bb, double *c){

    int initRow = initPos/ncols;
    int initCol = initPos%ncols;

    int maxRow = (initPos+offset)/ncols;
    int maxCol = (initPos+offset)%ncols;

    int colStop = ncols;
    int colStart = initCol;

    int n = 0;
    int i, j, k;

   for (i = initRow; i <= maxRow; i++) {
        if(i==maxRow){
            colStop = maxCol;
        }
        for(j = colStart;j < colStop;j++){

            c[n] = 0;

            for(k=0;k<ncols;k++){
                c[n] += aa[i*ncols+k] * bb[k*ncols+j];
            }
            n++;
        }
        colStart = 0;
    }

}
