
undefined4 ssl_set_peer_cert_type(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return 1;
}

