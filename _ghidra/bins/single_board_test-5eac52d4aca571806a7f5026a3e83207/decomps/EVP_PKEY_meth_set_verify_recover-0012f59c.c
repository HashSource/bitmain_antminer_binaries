
void EVP_PKEY_meth_set_verify_recover
               (EVP_PKEY_METHOD *pmeth,verify_recover_init *verify_recover_init,
               verify_recover *verify_recover)

{
  *(verify_recover_init **)(pmeth + 0x34) = verify_recover_init;
  *(verify_recover **)(pmeth + 0x38) = verify_recover;
  return;
}

