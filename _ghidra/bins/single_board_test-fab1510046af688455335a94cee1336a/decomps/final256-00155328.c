
void final256(int param_1,uchar *param_2)

{
  SHA256_Final(param_2,*(SHA256_CTX **)(param_1 + 0xc));
  return;
}

