# Hashira_assignment
## Problem
Given `n` roots in JSON format (with base and value), reconstruct the polynomial coefficients.  
Polynomial degree = `k - 1`, where `k` is provided in the JSON.

## Input
JSON file, e.g. `sample.json`:
```json
{
  "keys": { "n": 4, "k": 3 },
  "1": { "base": "10", "value": "4" },
  "2": { "base": "2",  "value": "111" },
  "3": { "base": "10", "value": "12" },
  "6": { "base": "4",  "value": "213" }
}
