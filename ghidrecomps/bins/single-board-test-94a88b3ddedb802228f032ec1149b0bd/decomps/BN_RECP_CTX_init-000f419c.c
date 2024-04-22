
void BN_RECP_CTX_init(BN_RECP_CTX *recp)

{
  BN_init(&recp->N);
  BN_init(&recp->Nr);
  recp->num_bits = 0;
  recp->flags = 0;
  return;
}

