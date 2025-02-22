#include <iostream>
using namespace std;

double hitungDeterminan2x2(double mat[2][2])
{
  return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

double hitungDeterminan3x3(double mat[3][3])
{
  return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

bool hitungInvers2x2(double mat[2][2], double invers[2][2])
{
  double det = hitungDeterminan2x2(mat);

  if (det == 0)
  {
    cout << "Matriks tidak memiliki invers karena determinan = 0.\n";
    return false;
  }

  invers[0][0] = mat[1][1] / det;
  invers[0][1] = -mat[0][1] / det;
  invers[1][0] = -mat[1][0] / det;
  invers[1][1] = mat[0][0] / det;

  return true;
}

void hitungKofaktor3x3(double mat[3][3], double kofaktor[3][3])
{
  kofaktor[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
  kofaktor[0][1] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
  kofaktor[0][2] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

  kofaktor[1][0] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]);
  kofaktor[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]);
  kofaktor[1][2] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]);

  kofaktor[2][0] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]);
  kofaktor[2][1] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]);
  kofaktor[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
}

bool hitungInvers3x3(double mat[3][3], double invers[3][3])
{
  double det = hitungDeterminan3x3(mat);

  if (det == 0)
  {
    cout << "Matriks tidak memiliki invers karena determinan = 0.\n";
    return false;
  }

  double kofaktor[3][3];
  hitungKofaktor3x3(mat, kofaktor);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      invers[j][i] = kofaktor[i][j] / det;
    }
  }

  return true;
}

void tampilkanMatriks2x2(double mat[2][2])
{
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

void tampilkanMatriks3x3(double mat[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

int main()
{
  int pilihan;
  cout << "Pilih ukuran matriks:\n";
  cout << "1. Matriks 2x2\n";
  cout << "2. Matriks 3x3\n";
  cout << "Pilihan: ";
  cin >> pilihan;

  if (pilihan == 1)
  {

    double matriks[2][2], invers[2][2];

    cout << "Masukkan elemen matriks 2x2:\n";
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        cout << "Masukkan elemen [" << i << "][" << j << "]: ";
        cin >> matriks[i][j];
      }
    }

    cout << "\nMatriks yang diinput:\n";
    tampilkanMatriks2x2(matriks);

    if (hitungInvers2x2(matriks, invers))
    {
      cout << "\nInvers matriks 2x2:\n";
      tampilkanMatriks2x2(invers);
    }
  }
  else if (pilihan == 2)
  {

    double matriks[3][3], invers[3][3];

    cout << "Masukkan elemen matriks 3x3:\n";
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        cout << "Masukkan elemen [" << i << "][" << j << "]: ";
        cin >> matriks[i][j];
      }
    }

    cout << "\nMatriks yang diinput:\n";
    tampilkanMatriks3x3(matriks);

    if (hitungInvers3x3(matriks, invers))
    {
      cout << "\nInvers matriks 3x3:\n";
      tampilkanMatriks3x3(invers);
    }
  }
  else
  {
    cout << "Pilihan tidak valid.\n";
  }

  return 0;
}