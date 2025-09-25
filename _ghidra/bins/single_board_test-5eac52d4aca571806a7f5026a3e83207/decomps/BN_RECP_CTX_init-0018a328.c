
void BN_RECP_CTX_init(BN_RECP_CTX *recp)

{
  memset(recp,0,0x34);
  bn_init(recp);
  bn_init(&recp->Nr);
  return;
}

