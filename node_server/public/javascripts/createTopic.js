$(document).ready(function () {
    const nameInput = $('#topicNameInput');
    const saveButton = $('#saveButton');
    const nameList = $('#topicList');

    // Function to fetch and display names
    function displayNames() {
        $.ajax({
            url: '/createTopics/readJson',
            method: 'GET',
            dataType: 'json',
            success: function (data) {
                nameList.html(data.map(entry => `<div>${entry.name}</div>`).join(''));
            },
            error: function (error) {
                console.error('Error fetching names:', error);
            }
        });
    }

    // Initial display of names
    displayNames();

    // Event listener for the "Save" button
    saveButton.click(function () {
        const newName = nameInput.val();

        // Send the name to the server to save it
        $.ajax({
            url: '/createTopics/writeJson',
            method: 'POST',
            contentType: 'application/json',
            data: JSON.stringify({ name: newName }),
            success: function (data) {
                if (data.success) {
                    // Clear the input field and display updated names
                    nameInput.val('');
                    displayNames();
                } else {
                    console.error('Failed to save the name.');
                }
            },
            error: function (error) {
                console.error('Error saving the name:', error);
            }
        });
    });
});
