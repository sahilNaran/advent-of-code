defmodule AOC do
  def solve() do
    grid =
      "input.txt"
      |> File.read!()
      |> String.split("\n", trim: true)
      |> Enum.map(&String.split(&1, "", trim: true))
      |> to_grid_map()

    num_rows = grid |> Map.keys() |> Enum.map(&elem(&1, 0)) |> Enum.max()

    dimensions = {
      num_rows,
      num_rows
    }

    parent = self()

    directions()
    |> Enum.map(
      &spawn_link(fn ->
        count = search_directions(grid, dimensions, &1)
        send(parent, {:count, &1, count})
      end)
    )

    directions()
    |> Enum.map(fn _ ->
      receive do
        {:count, _, count} -> count
      end
    end)
    |> Enum.sum()
    |> IO.inspect()
  end

  defp to_grid_map(list_grid) do
    for {row, row_idx} <- Enum.with_index(list_grid),
        {char, col_idx} <- Enum.with_index(row),
        into: %{} do
      {{row_idx, col_idx}, char}
    end
  end

  defp directions do
    [
      {:right, {0, 1}},
      {:down_right, {1, 1}},
      {:down, {1, 0}},
      {:down_left, {1, -1}},
      {:left, {0, -1}},
      {:up_left, {-1, -1}},
      {:up, {-1, 0}},
      {:up_right, {-1, 1}}
    ]
  end

  defp next_position({row, col}, {dx, dy}) do
    {row + dx, col + dy}
  end

  defp xmas_at_position?(grid, dimensions, start_position, direction) do
    "XMAS"
    |> String.split("", trim: true)
    |> check_xmas(grid, dimensions, start_position, direction)
  end

  defp check_xmas([], _, _, _, _), do: true

  defp check_xmas([letter | rest], grid, dimensions, position, direction) do
    case get_char(grid, dimensions, position) do
      {:ok, ^letter} ->
        check_xmas(rest, grid, dimensions, next_position(position, direction), direction)

      _ ->
        false
    end
  end

  defp get_char(grid, {max_row, max_col}, {row, col} = pos)
       when row >= 0 and row <= max_row and col >= 0 and col <= max_col do
    case Map.get(grid, pos) do
      nil -> :error
      char -> {:ok, char}
    end
  end

  defp get_char(_, _, _), do: :error

  defp search_directions(grid, {max_row, max_col} = dimensions, direction) do
    for row <- 0..max_row,
        col <- 0..max_col,
        xmas_at_position?(grid, dimensions, {row, col}, elem(direction, 1)),
        reduce: 0 do
      acc -> acc + 1
    end
  end
end

AOC.solve()
