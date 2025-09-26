
BIGNUM * ASN1_ENUMERATED_to_BN(ASN1_ENUMERATED *ai,BIGNUM *bn)

{
  BIGNUM *b;
  
  if ((ai->type & 0xfffffeffU) != 10) {
    ERR_put_error(0xd,0xe4,0xe1,"crypto/asn1/a_int.c",499);
    return (BIGNUM *)0x0;
  }
  b = BN_bin2bn(ai->data,ai->length,bn);
  if (b == (BIGNUM *)0x0) {
    ERR_put_error(0xd,0xe4,0x69,"crypto/asn1/a_int.c",0x1f9);
  }
  else if (ai->type << 0x17 < 0) {
    BN_set_negative(b,1);
    return b;
  }
  return b;
}

