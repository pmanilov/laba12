#ifndef laba9_h
#define laba9_h
class SqrMatrix
{
private:
    double** matrix;
    int size;
public:
    SqrMatrix(int sizeofmymatrix);
    SqrMatrix();
    SqrMatrix(SqrMatrix& M);
    void FillMatrix();
    void OutputMatrix();
    int Set(double x, int i, int j);
    double Get(int i, int j, int& error);
    SqrMatrix& operator= (const SqrMatrix& M);
    SqrMatrix operator+ (const SqrMatrix& M) const;
    SqrMatrix operator- (const SqrMatrix& M) const;
    SqrMatrix operator* (const SqrMatrix& M) const;
    SqrMatrix operator/ (const SqrMatrix& M) const;
    void operator*= (double x);
    ~SqrMatrix();
};

#endif /*laba9_h*/

