
BIGNUM * ASN1_ENUMERATED_to_BN(ASN1_ENUMERATED *ai,BIGNUM *bn)

{
  BIGNUM *b;
  
  b = BN_bin2bn(ai->data,ai->length,bn);
  if (b == (BIGNUM *)0x0) {
    ERR_put_error(0xd,0x71,0x69,"a_enum.c",0xb1);
  }
  else if (ai->type == 0x10a) {
    BN_set_negative(b,1);
  }
  return b;
}

