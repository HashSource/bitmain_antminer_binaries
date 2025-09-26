
int RSA_X931_hash_id(int nid)

{
  if (nid == 0x2a0) {
    return 0x34;
  }
  if (nid < 0x2a1) {
    if (nid == 0x40) {
      return 0x33;
    }
  }
  else {
    if (nid == 0x2a1) {
      return 0x36;
    }
    if (nid == 0x2a2) {
      return 0x35;
    }
  }
  return -1;
}

