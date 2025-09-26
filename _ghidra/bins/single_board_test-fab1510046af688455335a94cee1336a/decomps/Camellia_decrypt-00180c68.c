
void Camellia_decrypt(uchar *in,uchar *out,CAMELLIA_KEY *key)

{
  Camellia_DecryptBlock_Rounds(key->grand_rounds,in,key,out);
  return;
}

