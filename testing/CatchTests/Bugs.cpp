#include "catch.hpp"

#include <libIntegrate/Integrate.hpp>

#include "fakeit.hpp"

TEST_CASE("Passing integer limits")
{
  // passing integer literals to integrate functions is causing
  // integrand to evaluate to zero. probably caused by integer rounding
  // that leads to dx being zero
  auto f = [](double x) { return 1; };
  SECTION("Gaussian Quadrature")
  {
    SECTION("8'th Order")
    {
      _1D::GQ::GaussLegendreQuadrature<double, 8> integrate;
      CHECK(integrate(f, 0, 1) == Approx(1));
    }
    SECTION("16'th Order")
    {
      _1D::GQ::GaussLegendreQuadrature<double, 16> integrate;
      CHECK(integrate(f, 0, 1) == Approx(1));
    }
    SECTION("32'nd Order")
    {
      _1D::GQ::GaussLegendreQuadrature<double, 32> integrate;
      CHECK(integrate(f, 0, 1) == Approx(1));
    }
    SECTION("64'th Order")
    {
      _1D::GQ::GaussLegendreQuadrature<double, 64> integrate;
      CHECK(integrate(f, 0, 1) == Approx(1));
    }
  }
  SECTION("Riemann Sum")
  {
    _1D::RiemannRule<double> integrate;
    CHECK(integrate(f, 0, 1, 4) == Approx(1));
  }
  SECTION("Trapezoid Sum")
  {
    _1D::TrapezoidRule<double> integrate;
    CHECK(integrate(f, 0, 1, 4) == Approx(1));
  }
  SECTION("Simpson's Rule")
  {
    _1D::SimpsonRule<double> integrate;
    CHECK(integrate(f, 0, 1, 4) == Approx(1));
  }
}
