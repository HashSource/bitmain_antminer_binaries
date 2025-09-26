
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_idea_cbc(void)

{
  return (EVP_CIPHER *)&idea_cbc;
}

