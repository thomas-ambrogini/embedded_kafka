$(document).ready(function () {
  const nameInput = $("#topicNameInput");
  const saveButton = $("#saveButton");
  const nameList = $("#topicList");

  // Function to fetch and display names
  function displayNames() {
    $.ajax({
      url: "/createTopics/readJson",
      method: "GET",
      dataType: "json",
      success: function (data) {
        nameList.html(data.map((entry) => `<div>${entry.name}</div>`).join(""));
      },
      error: function (error) {
        console.error("Error fetching names:", error);
      },
    });
  }

  // Initial display of names
  displayNames();

  // Event listener for the "Save" button
  saveButton.click(function () {
    const newName = nameInput.val();

    // Send the name to the server to save it
    $.ajax({
      url: "/createTopics/writeJson",
      method: "POST",
      contentType: "application/json",
      data: JSON.stringify({ name: newName }),
      success: function (data) {
        if (data.success) {
          // Clear the input field and display updated names
          nameInput.val("");
          displayNames();
        } else {
          console.error("Failed to save the name.");
        }
      },
      error: function (error) {
        console.error("Error saving the name:", error);
      },
    });
  });
});

function set_proc_alive(proc, alive) {
  img = "img/led-red.jpg";
  if (proc == "core0") {
    id = "#core0-node-alive";
  }
  if (proc == "core1") {
    id = "#core1-node-alive";
  }
  if (proc == "core2") {
    id = "#core2-node-alive";
  }
  if (proc == "core3") {
    id = "#core3-node-alive";
  }
  if (proc == "a53") {
    id = "#a53-node-alive";
  }
  if (alive) {
    img = "img/led-green.jpg";
  }
  $(id).attr("src", img);
}

function proc_feature_active(proc, feature, active) {
  alert("Test - " + proc + " - " + feature + " - " + active);
}

$(document).ready(function () {
  set_proc_alive("core0", false);
  set_proc_alive("core1", false);
  set_proc_alive("core2", false);
  set_proc_alive("core3", false);
  set_proc_alive("a53", false);
  /* Menu */
  $("#menu-topics").click(function () {
    $("#menu-topics").addClass("topnav-active");
    $("#menu-nodes").removeClass("topnav-active");
    $("#section-topics").removeClass("section-hidden");
    $("#section-nodes").addClass("section-hidden");
  });
  $("#menu-nodes").click(function () {
    $("#menu-nodes").addClass("topnav-active");
    $("#menu-topics").removeClass("topnav-active");
    $("#section-nodes").removeClass("section-hidden");
    $("#section-topics").addClass("section-hidden");
  });
  /* Nodes actions */
  $("#core0-feat-test").click(function () {
    set_proc_alive("core0", $("#core0-feat-test").is(":checked"));
  });
  $("#core0-feat-meas").click(function () {
    proc_feature_active(
      "core0",
      "measures",
      $("#core0-feat-meas").is(":checked")
    );
  });
  $("#core0-feat-ctrl").click(function () {
    proc_feature_active(
      "core0",
      "control",
      $("#core0-feat-ctrl").is(":checked")
    );
  });
  $("#core1-feat-meas").click(function () {
    proc_feature_active(
      "core1",
      "measures",
      $("#core1-feat-meas").is(":checked")
    );
  });
  $("#core1-feat-ctrl").click(function () {
    proc_feature_active(
      "core1",
      "control",
      $("#core1-feat-ctrl").is(":checked")
    );
  });
  $("#core2-feat-meas").click(function () {
    proc_feature_active(
      "core2",
      "measures",
      $("#core2-feat-meas").is(":checked")
    );
  });
  $("#core2-feat-ctrl").click(function () {
    proc_feature_active(
      "core2",
      "control",
      $("#core2-feat-ctrl").is(":checked")
    );
  });
  $("#core3-feat-meas").click(function () {
    proc_feature_active(
      "core3",
      "measures",
      $("#core3-feat-meas").is(":checked")
    );
  });
  $("#core3-feat-ctrl").click(function () {
    proc_feature_active(
      "core3",
      "control",
      $("#core3-feat-ctrl").is(":checked")
    );
  });
  $("#a53-feat-meas").click(function () {
    proc_feature_active("a53", "measures", $("#a53-feat-meas").is(":checked"));
  });
  $("#a53-feat-ctrl").click(function () {
    proc_feature_active("a53", "control", $("#a53-feat-ctrl").is(":checked"));
  });
});
