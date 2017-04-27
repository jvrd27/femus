#ifndef ELLIPTIC_BDRY_PARAMETERS
#define ELLIPTIC_BDRY_PARAMETERS


//*********************** Sets Number of subdivisions in X and Y direction *****************************************

#define NSUB_X  16
#define NSUB_Y  16


//*********************** Sets the regularization parameters *******************************************************

#define ALPHA_CTRL 1.e-3
#define BETA_CTRL 1.e-8



//*********************** Find volume elements that contain a  Target element **************************************

int ElementTargetFlag(const std::vector<double> & elem_center) {

 //***** set target domain flag ******
  int target_flag = 0; //set 0 to 1 to get the entire domain
  
   if (   elem_center[0] < 0.75 + 1.e-5    && elem_center[0] > 0.25  - 1.e-5  && 
        /*elem_center[1] <  1.  + 1.e-5  &&*/ elem_center[1] > 0.7 - (1./16. + 1./64.) - 1.e-5 
  ) {
     
     target_flag = 1;
     
  }
  
     return target_flag;

}



//*********************** Find volume elements that contain a Control Face element *********************************

// int ControlDomainFlag(const std::vector<double> & elem_center) {
// 
//  //***** set control domain flag ***** 
//   double mesh_size = 1./NSUB_Y;
//   int control_el_flag = 0; //set 0 to 1 to get the entire domain
//    if ( elem_center[1] >  1. - mesh_size ) { control_el_flag = 1; }
// 
//      return control_el_flag;
// }

int ControlDomainFlag(const std::vector<double> & elem_center) {

 //***** set target domain flag ******
 // flag = 1: we are in the lifting nonzero domain
  int control_el_flag = 0;
   if ( elem_center[1] >  0.4 ) { control_el_flag = 1; }

     return control_el_flag;

}


//******************************************* Desired Target *******************************************************

double DesiredTarget()
{
   return 1.;
}




#endif