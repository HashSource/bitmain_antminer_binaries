
int EVP_MD_block_size(EVP_MD *md)

{
  return (int)md->sign;
}

