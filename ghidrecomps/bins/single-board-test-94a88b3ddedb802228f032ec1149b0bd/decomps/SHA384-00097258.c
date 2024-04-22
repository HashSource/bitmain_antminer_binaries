
uchar * SHA384(uchar *d,size_t n,uchar *md)

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
  
  local_f8._0_4_ = DAT_00097300;
  local_f8._4_4_ = DAT_00097304;
  md_00 = &m_7551;
  if (md != (uchar *)0x0) {
    md_00 = md;
  }
  local_f0 = DAT_00097308;
  uStack_ec = DAT_0009730c;
  local_e0 = DAT_00097310;
  uStack_dc = DAT_00097314;
  local_e8 = DAT_00097318;
  uStack_e4 = DAT_0009731c;
  local_d8 = DAT_00097320;
  uStack_d4 = DAT_00097324;
  local_28 = 0;
  local_24 = 0x30;
  local_d0 = DAT_00097330;
  uStack_cc = DAT_00097334;
  local_c0 = DAT_00097328;
  uStack_bc = DAT_0009732c;
  local_b8 = 0;
  uStack_b4 = 0;
  local_c8 = DAT_00097338;
  uStack_c4 = DAT_0009733c;
  local_b0 = 0;
  uStack_ac = 0;
  SHA512_Update((SHA512_CTX *)local_f8,d,n);
  SHA512_Final(md_00,(SHA512_CTX *)local_f8);
  OPENSSL_cleanse(local_f8,0xd8);
  return md_00;
}

