
BIGNUM * ASN1_INTEGER_to_BN(ASN1_INTEGER *ai,BIGNUM *bn)

{
  BIGNUM *b;
  
  b = BN_bin2bn(ai->data,ai->length,bn);
  if (b == (BIGNUM *)0x0) {
    ERR_put_error(0xd,0x77,0x69,DAT_000b5a30,0x1c8);
  }
  else if (ai->type == 0x102) {
    BN_set_negative(b,1);
  }
  return b;
}

