# 📘 Multi-Stage Sigmoid Model  
An advanced analytical framework for multi-phase behaviors 🚀

---

## 📌 Overview  
The **Multi-Stage Sigmoid Model** is an analytical model based on a smart combination of multiple logistic (sigmoid) functions, designed to simulate **two-phase or multi-phase behavior**.  
This model can accurately capture patterns that begin with growth, then transition through correction, and finally converge to a stable state.

---

## ⭐ Features  
- Multi-stage **S-curve modeling**  
- Smooth transitions between growth phases  
- Applicable to biology, control systems, human learning, technology adoption, and more  
- Includes **exact formula**, **analytical integral**, and **multi-function structure**

---

## 📐 Model Parameters  
| Parameter | Description |
|----------|-------------|
| `A` | Upper bound of the first stage (initial ceiling) |
| `y₁` | Initial bias value |
| `y₂` | Final value after the second phase |
| `k` | Sigmoid slope coefficient (transition rate) |
| `b` | Starting point of the second phase |
| `x` | Independent variable |

---

## 🟦 Main Function: **g(x)**

```math
g(x) = (A - y_1)\left(\frac{1}{1 + e^{-kx}} - \frac{1}{1 + e^{-k(x-b)}}\right)
      + (y_2 - y_1)\left(\frac{1}{1 + e^{-k(x-b)}}\right)
      + y_1
```

This function consists of four components:

```math
f(x) = \frac{A - y_1}{1 + e^{-kx}}
```

```math
f_1(x) = -\frac{A - y_1}{1 + e^{-k(x-b)}}
```

```math
f_2(x) = (y_2 - y_1)\left(\frac{1}{1 + e^{-k(x-b)}}\right)
```

```math
f_3(x) = y_1
```

Combined:

```math
g(x) = f(x) + f_1(x) + f_2(x) + f_3(x)
```

---

## 🟥 Antiderivatives (Integrals)

```math
F(x) = \frac{A - y_1}{k}\ln(1 + e^{kx}) - 1.75480298876
```

```math
F_1(x) = -\frac{A - y_1}{k}\ln(1 + e^{k(x-b)})
```

```math
F_2(x) = \frac{y_2 - y_1}{k}\ln(1 + e^{k(x-b)})
```

```math
F_3(x) = y_1 x
```

### **Final Integrated Model: F₄(x)**

```math
F_4(x) = F(x) + F_1(x) + F_2(x) + F_3(x)
        + 7.7348261129 \times 10^{-10}
```

---

## 📊 Model Behavior  
### 🔹 Phase 1:  
Rapid sigmoid-like growth from the starting point toward `A`.

### 🔹 Middle Phase:  
Temporary stabilization, caused by activation of the second sigmoid.

### 🔹 Phase 2:  
Smooth, stable transition toward `y₂`.

---

## 🚀 Applications  
- Modeling data with multi-phase growth patterns  
- Biological systems (activation curves, neural responses)  
- Control systems with adaptive phase transitions  
- Industrial processes featuring delay + saturation  
- Complex multi-stage learning curves  

---

# 📘 C Function Reference  
### Complete Description of the Multi-Stage Sigmoid Speed Profile Functions

---

### 📌 Function Explanations

The **`g(x, p)`** function is the core of the model and computes the instantaneous speed or output at a given `x`. It is a multi-stage version of a sigmoid function, generating a smooth, two-phase velocity profile suitable for applications such as door-motion control.

The **`integral_g(x, p)`** function computes the exact analytical integral of `g` from 0 to `x`. It performs extremely fast and returns the traveled distance with zero numerical error. It is typically used to compute moment-by-moment position.

The **`integral_g_endpoint(p)`** function calculates the total distance traveled by the system once the second phase of the model fully completes (as `x → ∞`). This value is used to fine-tune the **end_point** parameter to achieve a target travel distance (e.g., 0.90 meters).

The **`compute_y1(g_start, p)`** function automatically computes the correct **y1** parameter based on the starting velocity (`g(0) = g_start`). This ensures the model behaves accurately even when the initial acceleration is not zero.

The **`find_end_point(p, target_distance_meters)`** function uses the Newton–Raphson algorithm with safety guards to find the correct **end_point** such that the model’s total distance exactly matches the target. This ensures the door or mechanism stops precisely at the desired location.

The **`trapezoidalIntegral(...)`** and **`simpsonIntegral(...)`** functions provide numerical integration options. The trapezoidal method serves as a backup when the parameter `k` is highly sensitive, while Simpson’s method offers higher precision and is recommended for most numerical work.

Finally, the **`auto_calibrate_door(door)`** function acts like an adaptive learning system. It evaluates the average travel distance of the last 20 door movements and adjusts the **end_point** accordingly, making the model more accurate and aligned with real mechanical behavior over time.

---

## 👨‍💻 Author  
Model Developer: **[Mohammad Esteghamat]**  
Feel free to reach out if you're interested in collaboration, development, or research use.

---

## ⭐ If this project helped you…  
Consider starring the GitHub repository!

