#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d
{
	public:
		int x;
		int y;
		int z;
		
	public :
		Vector3d(int x_,int y_,int z_){
			x=x_;
			y=y_;
			z=z_;
		}
		bool igual( const Vector3d & vector2) const{
			if(x==vector2.x && y==vector2.y && z==vector2.z){
				return true;
			}
			return false;
		}
		double normaMax();
		
		
};

#endif
