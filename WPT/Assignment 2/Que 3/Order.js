
"use strict";

// 1. Menu items stored in an array of objects
const menu = [
    { id: 1, name: "Coffee", price: 80 },
    { id: 2, name: "Tea", price: 40 },
    { id: 3, name: "Veg Sandwich", price: 120 },
    { id: 4, name: "Chocolate Cake", price: 150 },
    { id: 5, name: "Cold Coffee", price: 110 }
];

// Store selected items
let cart = [];

// 2. Load menu items into dropdown using a loop
function loadMenu() {
    const itemSelect = document.getElementById("itemSelect");

    menu.forEach(function (item) {
        const option = document.createElement("option");
        option.setAttribute("value", item.id);
        option.textContent = `${item.name} - ₹${item.price}`;
        itemSelect.appendChild(option);
    });
}

// 3. Add item to the order
function addToOrder() {
    const itemId = parseInt(
        document.getElementById("itemSelect").value
    );

    const quantity = parseInt(
        document.getElementById("quantity").value
    );

    const error = document.getElementById("quantityError");
    error.textContent = "";

    if (!Number.isInteger(quantity) || quantity <= 0) {
        error.textContent = "Please enter a quantity greater than 0.";
        return;
    }

    const item = menu.find(function (product) {
        return product.id === itemId;
    });

    if (!item) {
        error.textContent = "Please select a valid item.";
        return;
    }

    const cartItem = {
        id: item.id,
        name: item.name,
        price: item.price,
        quantity: quantity
    };

    cart.push(cartItem);

    renderOrder();
    updateBill();

    document.getElementById("quantity").value = "";
}

// 4. Display order items and Remove buttons
function renderOrder() {
    const orderList = document.getElementById("orderList");
    orderList.innerHTML = "";

    cart.forEach(function (item) {
        const li = document.createElement("li");

        li.textContent =
            `${item.name} × ${item.quantity} = ₹${item.price * item.quantity} `;

        const removeButton = document.createElement("button");
        removeButton.textContent = "Remove";

        removeButton.onclick = function () {
            cart = cart.filter(function (cartItem) {
                return cartItem !== item;
            });

            renderOrder();
            updateBill();
        };

        li.appendChild(removeButton);
        orderList.appendChild(li);
    });
}

// 5. Calculate delivery charge using switch
function getDeliveryCharge() {
    const area = document.getElementById("deliveryArea").value;

    switch (area) {
        case "local":
            return 20;
        case "nearby":
            return 40;
        case "far":
            return 70;
        default:
            return 0;
    }
}

// 6. Calculate discount using if / else-if
function getDiscount(subtotal) {
    if (subtotal >= 1000) {
        return subtotal * 0.15;
    } else if (subtotal >= 500) {
        return subtotal * 0.10;
    } else if (subtotal >= 200) {
        return subtotal * 0.05;
    } else {
        return 0;
    }
}

// 7. Callback function
function applyRule(amount, rule) {
    return rule(amount);
}

// 8. Calculate and display the bill
function updateBill() {
    const subtotal = cart.reduce(function (total, item) {
        return total + item.price * item.quantity;
    }, 0);

    const discount = getDiscount(subtotal);
    const delivery = getDeliveryCharge();
    const finalTotal = subtotal - discount + delivery;

    const totalItems = cart.reduce(function (sum, item) {
        return sum + item.quantity;
    }, 0);

    // Conditional (ternary) operator
    const itemText = totalItems === 1
        ? "1 item"
        : `${totalItems} items`;

    // Callback using an anonymous function
    const result1 = applyRule(subtotal, function (amount) {
        return amount * 0.95;
    });

    // Callback using an arrow function
    const result2 = applyRule(subtotal, amount => amount * 0.90);

    console.log("Anonymous callback result:", result1);
    console.log("Arrow callback result:", result2);

    // Template literal to display the bill
    document.getElementById("bill").textContent =
        `Items: ${itemText}\n` +
        `Subtotal: ₹${subtotal.toFixed(2)}\n` +
        `Discount: -₹${discount.toFixed(2)}\n` +
        `Delivery charge: ₹${delivery.toFixed(2)}\n` +
        `Final total: ₹${finalTotal.toFixed(2)}`;
}

// 9. Promise: place order after 2 seconds
function processOrder() {
    return new Promise(function (resolve, reject) {
        setTimeout(function () {
            if (cart.length === 0) {
                reject("Your cart is empty. Please add an item first.");
            } else {
                const orderNumber = Math.floor(
                    100000 + Math.random() * 900000
                );

                resolve(orderNumber);
            }
        }, 2000);
    });
}

// 10. Async / await and try / catch
async function placeOrder() {
    const message = document.getElementById("orderMessage");
    const button = document.getElementById("placeOrderBtn");

    message.textContent = "Placing your order...";
    button.disabled = true;

    try {
        const orderNumber = await processOrder();

        message.textContent =
            `Order placed successfully! Order number: ${orderNumber}`;

        cart = [];
        renderOrder();
        updateBill();
    } catch (error) {
        message.textContent = error;
    } finally {
        button.disabled = false;
    }
}

// 11. Show special offer after 3 seconds
function showSpecialOffer() {
    setTimeout(function () {
        document.getElementById("specialOffer").textContent =
            "Special Offer: Get 10% off orders worth ₹500 or more!";
    }, 3000);
}

// 12. Run when the page loads
loadMenu();
updateBill();
showSpecialOffer();
