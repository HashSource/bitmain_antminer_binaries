
void EVP_PKEY_asn1_set_public
               (EVP_PKEY_ASN1_METHOD *ameth,pub_decode *pub_decode,pub_encode *pub_encode,
               pub_cmp *pub_cmp,pub_print *pub_print,pkey_size *pkey_size,pkey_bits *pkey_bits)

{
  *(pub_decode **)(ameth + 0x14) = pub_decode;
  *(pub_encode **)(ameth + 0x18) = pub_encode;
  *(pub_cmp **)(ameth + 0x1c) = pub_cmp;
  *(pub_print **)(ameth + 0x20) = pub_print;
  *(pkey_size **)(ameth + 0x30) = pkey_size;
  *(pkey_bits **)(ameth + 0x34) = pkey_bits;
  return;
}

