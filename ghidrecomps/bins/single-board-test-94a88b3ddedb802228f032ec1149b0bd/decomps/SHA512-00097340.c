
uchar * SHA512(uchar *d,size_t n,uchar *md)

{
  uchar *md_00;
  undefined local_f8 [8];
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  uint local_28;
  uint local_24;
  
  local_e8 = DAT_000973e0;
  uStack_e4 = DAT_000973e4;
  local_e0 = DAT_000973f0;
  uStack_dc = DAT_000973f4;
  local_f8._0_4_ = DAT_000973e8;
  local_f8._4_4_ = DAT_000973ec;
  md_00 = DAT_00097420;
  if (md != (uchar *)0x0) {
    md_00 = md;
  }
  local_d8 = DAT_00097400;
  uStack_d4 = DAT_00097404;
  local_f0 = DAT_000973f8;
  uStack_ec = DAT_000973fc;
  local_28 = 0;
  local_c8 = DAT_00097410;
  uStack_c4 = DAT_00097414;
  local_24 = 0x40;
  local_d0 = DAT_00097408;
  uStack_cc = DAT_0009740c;
  local_c0 = DAT_00097418;
  uStack_bc = DAT_0009741c;
  local_b8 = 0;
  uStack_b4 = 0;
  local_b0 = 0;
  uStack_ac = 0;
  SHA512_Update((SHA512_CTX *)local_f8,d,n);
  SHA512_Final(md_00,(SHA512_CTX *)local_f8);
  OPENSSL_cleanse(local_f8,0xd8);
  return md_00;
}

