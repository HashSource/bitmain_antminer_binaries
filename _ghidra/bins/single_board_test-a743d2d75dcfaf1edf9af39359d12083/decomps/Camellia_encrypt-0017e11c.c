
void Camellia_encrypt(uchar *in,uchar *out,CAMELLIA_KEY *key)

{
  Camellia_EncryptBlock_Rounds(key->grand_rounds,in,key,out);
  return;
}

