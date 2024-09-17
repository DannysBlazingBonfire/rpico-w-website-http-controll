
//update LED with a new state
function updateLed(state) {
    fetch(`/dashboard/led/${state}`)
    .then(response => response.text())
    .then(data => {
        document.getElementById('status').innerText = data;
    })
    .catch(error => {
        document.getElementById('status').innerText = 'Error: ${error}';
    });
}