
X509_ALGOR * PKCS5_pbe2_set(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen)

{
  X509_ALGOR *pXVar1;
  
  pXVar1 = PKCS5_pbe2_set_iv(cipher,iter,salt,saltlen,(uchar *)0x0,-1);
  return pXVar1;
}

