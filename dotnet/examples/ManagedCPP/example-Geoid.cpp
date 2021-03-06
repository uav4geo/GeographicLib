using namespace System;
using namespace NETGeographicLib;

int main(array<System::String ^> ^/*args*/)
{
    try {
        Geoid^ egm96 = gcnew Geoid("egm96-5", "", true, false);
        // Convert height above egm96 to height above the ellipsoid
        double lat = 42, lon = -75, height_above_geoid = 20;
        double
            geoid_height = egm96->Height(lat, lon),
            height_above_ellipsoid = (height_above_geoid +
                (double)Geoid::ConvertFlag::GEOIDTOELLIPSOID * geoid_height);
        Console::WriteLine(height_above_ellipsoid);
    }
    catch (GeographicErr^ e) {
        Console::WriteLine(String::Format("Caught exception: {0}", e->Message));
        return -1;
    }
    return 0;
}
