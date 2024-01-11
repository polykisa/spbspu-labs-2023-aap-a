#include <string>
#include <map>
#include "input_output_shapes.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "complexquad.hpp"
#include "geometric_functions.hpp"


namestnikov::Shape ** namestnikov::inputShapes(std::istream & in, size_t & count)
{
  using namespace namestnikov;
  std::map<std::string, size_t> possibleShapes;
  possibleShapes["RECTANGLE"] = 4;
  possibleShapes["CIRCLE"] = 3;
  possibleShapes["COMPLEXQUAD"] = 8;
  double * currentParameters = nullptr;
  std::string currentShapeName = "";
  namestnikov::Shape ** currentShapes = nullptr;
  namestnikov::Shape ** oldShapes = nullptr;
  while (in >> currentShapeName)
  {
    if (currentShapeName == "SCALE")
    {
      break;
    }
    else
    {
      for (auto now : possibleShapes)
      {
        std::string shapeName = now.first;
        size_t possibleSize = now.second;
        if (currentShapeName == shapeName)
        {
          ++count;
          currentParameters = new double[possibleSize];
          for (size_t i = 0; i < possibleSize; ++i)
          {
            in >> currentParameters[i];
          }
          if (!in)
          {
            delete [] currentParameters;
            delete [] currentShapes;
            delete [] oldShapes;
            throw std::invalid_argument("Error in input\n");
          }
          oldShapes = currentShapes;
          currentShapes = new Shape * [count];
          if (oldShapes)
          {
            for (size_t i = 0; i < count; ++i)
            {
              currentShapes[i] = oldShapes[i];
            }
          }
          delete [] oldShapes;
          try
          {
            if (currentShapeName == "RECTANGLE")
            {
              currentShapes[count - 1] = new Rectangle({currentParameters[0], currentParameters[1]}, {currentParameters[2], currentParameters[3]});
            }
            else if (currentShapeName == "CIRCLE")
            {
              currentShapes[count - 1] = new Circle({currentParameters[0], currentParameters[1]}, currentParameters[2]);
            }
            else if (currentShapeName == "COMPLEXQUAD")
            {
              point_t * points = new point_t[4];
              for (size_t j = 0; j < 8; j += 2)
              {
                points[j / 2] = {currentParameters[j], currentParameters[j + 1]};
              }
              currentShapes[count - 1] = new Complexquad(points);
            }
          }
          catch (...)
          {
            deleteShapes(currentShapes, count);
            throw;
          }
          delete [] currentParameters;
        }
      }
      in >> std::noskipws;
      char sym = 0;
      while (sym != '\n')
      {
        in >> sym;
      }
      in >> std::skipws;
    }
  }
  return currentShapes;
}

std::ostream & namestnikov::outputShapes(std::ostream & out, size_t count, Shape ** shapes)
{
  double square = 0.0;
  for (size_t i = 0; i < count; ++i)
  {
    if (shapes[i])
    {
      square += shapes[i]->getArea();
    }
  }
  out << square << " ";
  for (size_t i = 0; i < count; ++i)
  {
    if (shapes[i])
    {
      double width = shapes[i]->getFrameRect().width;
      double height = shapes[i]->getFrameRect().height;
      point_t position = shapes[i]->getFrameRect().pos;
      double positionX = position.x;
      double positionY = position.y;
      out << positionX - (width / 2.0) << " " << positionY - (height / 2.0) << " "
           << positionX + (width / 2.0) << " " << positionY + (height / 2.0);
    }
  }
  out << "\n";
  return out;
}
