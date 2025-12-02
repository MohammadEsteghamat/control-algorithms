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



# 📘 Multi-Stage Sigmoid Model  
یک مدل تحلیلی پیشرفته برای رفتارهای چندمرحله‌ای 🚀

---

## 📌 Overview  
**Multi-Stage Sigmoid Model** یک مدل تحلیلی مبتنی بر ترکیب هوشمندانه‌ی چند تابع لجستیک (سیگموئید) است که برای شبیه‌سازی رفتارهای **دو فاز یا چندمرحله‌ای** طراحی شده است.  
این مدل قادر است الگوهایی را که ابتدا رشد، سپس اصلاح، و در نهایت به یک حالت پایدار همگرا می‌شوند، با دقت بالا توصیف کند.

---

## ⭐ Features  
- مدل‌سازی **S-curve چندمرحله‌ای**
- گذار نرم بین فازهای رشد
- قابل استفاده در زیست‌شناسی، کنترل، یادگیری انسانی، پذیرش فناوری و…
- شامل **فرمول دقیق**، **انتگرال تحلیلی**، و **ساختار چندتابعی**

---

## 📐 Model Parameters  
| پارامتر | توضیح |
|--------|-------|
| `A` | حد بالای مرحله اول (سقف اولیه) |
| `y₁` |مقدار بایاس نقطه شروع |
| `y₂` | مقدار نهایی پس از فاز دوم |
| `k` | ضریب شیب سیگموئید (سرعت گذار) |
| `b` | نقطه شروع فاز دوم |
| `x` | متغیر مستقل |

---

## 🟦 Main Function: **g(x)**

```math
g\left(x\right)\ =\ \left\{x\ge0:\left(A-y_{1}\right)*\left(\frac{1}{1+e^{-kx}}-\frac{1}{1+e^{-k(x-b)}}\right)+\left(y_{2}-y_{1}\right)\left(\frac{1}{1+e^{-k(x-b)}}\right)+y_{1}\right\}
```

این تابع چهار مؤلفه اصلی دارد:




 
```math
f\left(x\right)\ = \left\{x\ge0:\frac{\left(A-y_{1}\right)}{1+e^{-kx}}\right\}
 ```


 
```math
f_{1}\left(x\right)\ = \ \left\{x\ge0:-\frac{\left(A-y_{1}\right)}{1+e^{-k(x-b)}}\right\}
 ```


 
```math
f_{2}\left(x\right)\ = \left\{x\ge0:\left(y_{2}-y_{1}\right)\left(\frac{1}{1+e^{-k(x-b)}}\right)\right\}
 ```


 
```math
f_{3}\left(x\right)\ = \left\{x\ge0:\ y_{1}\right\}
 ```

ترکیب آنها:  
```math
g(x) = f(x) + f_1(x) + f_2(x) + f_3(x)
```

---

## 🟥 Antiderivatives (Integrals)

```math
F\left(x\right) = \frac{\left(A-y_{1}\right)}{k}\ln\left(1+e^{kx}\right)-1.75480298876
 ```


 
```math
F_{1}\left(x\right) = -\frac{A-y_{1}}{k}\ln\left(1+e^{k\left(x-b\right)}\right)

 ```

 
```math
F_{2}\left(x\right) = \frac{y_{2}-y_{1}}{k}\ln\left(1+e^{k\left(x-b\right)}\right)
 ```


 
```math
F_{3}\left(x\right)\ = \ y_{1}x
 ```

### **Final Integrated Model: F₄(x)**

```math
F_4(x) = F(x) + F_1(x) + F_2(x) + F_3(x) +
7.7348261129 \times 10^{-10}
```

---

## 📊 Model Behavior  
### 🔹 فاز اول:  
رشد سریع سیگموئیدی از `نقطه شروع` تا نزدیک `A`.

### 🔹 فاز میانی:  
 تثبیت موقت، ناشی از فعال شدن سیگموئید دوم.

### 🔹 فاز دوم:  
گذار نرم و پایدار به سمت `y₂`.

---

## 🚀 Applications  
- Data modeling with multi-phase growth patterns  
- Biological systems (activation curves, neural response)  
- Control systems with adaptive phase transition  
- Industrial processes with delay + saturation  
- Complex multi-stage learning curves  

---
# 📘 C Function Reference  
### توضیح کامل توابع مدل پروفایل سرعت سیگموئیدی چندمرحله‌ای

در این بخش، توضیحات تمام توابع اصلی مدل به‌صورت متنی و پیوسته ارائه شده است تا درک دقیق‌تری از نقش و کاربرد هر کدام داشته باشید.

---

### 📌 توضیح توابع

تابع **`g(x, p)`** هستهٔ اصلی مدل است و مقدار سرعت یا خروجی لحظه‌ای را در نقطهٔ `x` محاسبه می‌کند. این تابع نسخه‌ای چندمرحله‌ای از یک تابع سیگموئیدی است و یک پروفایل سرعت دوفازی، نرم و کنترل‌پذیر ایجاد می‌کند که برای کاربردهایی مثل کنترل حرکت درب بسیار مناسب است.

تابع **`integral_g(x, p)`** نسخهٔ تحلیلی و دقیق انتگرال تابع `g` از 0 تا `x` را محاسبه می‌کند. این روش بسیار سریع است و بدون هیچ‌گونه خطای عددی، مسافت پیموده‌شده تا لحظهٔ موردنظر را برمی‌گرداند. این تابع معمولاً به‌عنوان مبنای محاسبه موقعیت لحظه‌ای استفاده می‌شود.

تابع **`integral_g_endpoint(p)`** مسافت کل طی‌شده توسط سیستم را پس از اتمام کامل فاز دوم مدل (یعنی زمانی که `x` به سمت بی‌نهایت میل می‌کند) محاسبه می‌کند. از این مقدار برای تنظیم دقیق پارامتر **end_point** جهت رسیدن به مسافت هدف (مثلاً 0.90 متر) استفاده می‌شود.

تابع **`compute_y1(g_start, p)`** به‌طور خودکار مقدار پارامتر **y1** را بر اساس سرعت واقعی لحظهٔ شروع (`g(0) = g_start`) محاسبه می‌کند. این ویژگی باعث می‌شود مدل حتی زمانی که شتاب اولیه صفر نیست نیز به‌صورت دقیق و منطبق رفتار کند.

تابع **`find_end_point(p, target_distance_meters)`** با استفاده از الگوریتم نیوتن-رافسون و همراه با گاردهای ایمنی، مقدار مناسب **end_point** را پیدا می‌کند تا مسافت کل مدل دقیقاً برابر مقدار هدف باشد. این ساختار تضمین می‌کند که درب یا مکانیزم، دقیقاً در نقطهٔ مورد نظر متوقف شود.

توابع **`trapezoidalIntegral(...)`** و **`simpsonIntegral(...)`** نسخه‌های عددی انتگرال‌گیری هستند. روش ذوزنقه‌ای معمولاً در شرایط خاص (مثل زمانی که حساسیت به پارامتر k زیاد است) به‌عنوان بکاپ استفاده می‌شود، درحالی‌که روش سیمپسون دقت بالاتری دارد و برای محاسبات عددی توصیه می‌شود.

در نهایت، تابع **`auto_calibrate_door(door)`** نقش یک سیستم یادگیری تطبیقی را ایفا می‌کند. این تابع میانگین مسافت ۲۰ حرکت اخیر درب را بررسی کرده و براساس رفتار واقعی مکانیکی، مقدار **end_point** را تنظیم می‌کند. به این ترتیب مدل به‌طور خودکار در طول زمان دقیق‌تر و سازگارتر می‌شود.


---

## 👨‍💻 Author  
توسعه‌دهنده مدل: **[محمد استقامت]**  
اگر علاقه‌مند به همکاری، توسعه، یا استفاده پژوهشی هستید خوشحال می‌شوم در ارتباط باشید.

---

## ⭐ اگر این پروژه کمک‌تان کرد…  
می‌توانید با ⭐ دادن به مخزن GitHub از آن حمایت کنید!
