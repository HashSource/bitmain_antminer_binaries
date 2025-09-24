
void ED25519_public_from_private(int param_1,uchar *param_2)

{
  undefined1 auStack_170 [40];
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  undefined1 auStack_120 [40];
  byte local_f8 [31];
  byte local_d9;
  undefined1 auStack_b8 [40];
  undefined1 auStack_90 [40];
  undefined1 auStack_68 [80];
  
  SHA512(param_2,0x20,local_f8);
  local_d9 = local_d9 & 0x3f | 0x40;
  local_f8[0] = local_f8[0] & 0xf8;
  ge_scalarmult_base(auStack_b8,local_f8);
  fe_invert(auStack_170,auStack_68);
  fe_mul(&local_148,auStack_b8,auStack_170);
  fe_mul(auStack_120,auStack_90,auStack_170);
  fe_tobytes(param_1,auStack_120);
  *(byte *)(param_1 + 0x1f) =
       *(byte *)(param_1 + 0x1f) ^
       (byte)((local_148 -
               (local_124 +
                (local_128 +
                 (local_12c +
                  (local_130 +
                   (local_134 +
                    (local_138 +
                     (local_13c +
                      (local_140 +
                       (local_144 + (local_148 + (local_124 * 0x13 + 0x1000000 >> 0x19) >> 0x1a) >>
                       0x19) >> 0x1a) >> 0x19) >> 0x1a) >> 0x19) >> 0x1a) >> 0x19) >> 0x1a) >> 0x19)
              & 1U) << 7);
  OPENSSL_cleanse(local_f8,0x40);
  return;
}

