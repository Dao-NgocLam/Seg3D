/*
 For more information, please see: http://software.sci.utah.edu
 
 The MIT License
 
 Copyright (c) 2016 Scientific Computing and Imaging Institute,
 University of Utah.
 
 
 Permission is hereby granted, free of charge, to any person obtaining a
 copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
*/

// Boost includes
#include <boost/filesystem.hpp>

#include <sstream>
#include <iomanip>
#include <fstream>

// Application includes
#include <Application/LayerIO/Actions/ActionExportVector.h>
#include <Application/LayerIO/LayerIO.h>
#include <Application/Layer/LayerManager.h>
#include <Application/ProjectManager/ProjectManager.h>

// REGISTER ACTION:
// Define a function that registers the action. The action also needs to be
// registered in the CMake file.
CORE_REGISTER_ACTION( Seg3D, ExportPoints )
CORE_REGISTER_ACTION( Seg3D, ExportMatrix )

namespace Seg3D
{

  void PointWriter::operator()(std::ostream& o, const Core::Point& p) const
  {
    o << p.x() << " " << p.y() << " " << p.z() << std::endl;
  }

  void MatrixDoubleWriter::operator()(std::ostream& o, const double& x) 
  {
    index_++;
    o << x << "\t";
    if (index_ % dim2_ == 0)
    {
      o << std::endl;
    }
  }

  //template class ActionExportVector<Core::Point, PointWriter>;

} // end namespace Seg3D
