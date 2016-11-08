#include "BlockFunctions.h"

int main(int argc, char const *argv[]) {

  //Fixed Size--------------------------------------
  struct Persona_FS test;
  init_fspersona(&test);
  new_fspersona("Carlos", "Velasquez", 21);
  new_fspersona("Melissa", "Robles", 22);
  new_fspersona("Alejandra", "Perdomo", 19);

  int fsregistries = fs_rsize();
  int fsreg_size = 44;
  char *fsdata = malloc(fsreg_size*fsregistries);

  int pos = 0, i = 0;

  for(i = 0; i < fsregistries; i++)
  {
    FSdata_w(fsdata, &test, i, fsreg_size);
    pos += fsreg_size;
  }

  struct Persona_FS test2;
  init_fspersona(&test2);
  pos = 0;

  for( i = 0; i < fsregistries; i++)
  {
    FSdata_r(fsdata, &test2, i, fsreg_size);
    pos += fsreg_size;
  }
  print_persona_fs(&test2);

  return 0;
}
